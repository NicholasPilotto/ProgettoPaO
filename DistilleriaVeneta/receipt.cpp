#include "receipt.h"

receipt::receipt() : date(steady_clock::now()), items(u_vector<pair<deep_ptr<product>, int>>()) {}

void receipt::add_item(const deep_ptr<product>& p) {
  pair<deep_ptr<product>, int> element(p, 1);
  if(!presenza(element.first)){
    items.push_back(element);
  }
}

void receipt::remove_item(std::string name, std::string dim) {
      u_vector<pair<deep_ptr<product>, int>>::iterator it = items.begin();
      u_vector<pair<deep_ptr<product>, int>>::iterator end = items.end();

      for(;it!=end;it++){
          if((*it).first->get_name() == name && (*it).first->fromKindToStdString((*it).first->get_kind()) == dim){
              items.erase(it);
          }
      }

//  for (int j = 0; j<i ; j++) {it++;}

//  items.erase(it);

  // std::cout  << "Inizio" << std::endl;
  // std::cout << items.size() << std::endl;

//      items.erase(items.begin() + i);


  // std::cout << items.size() << std::endl;
  //std::cout << "Fine" << std::endl;
}

void receipt::delete_all() { items.erase(items.begin(), items.end()); }

void receipt::refresh_quantity(const deep_ptr<product>& p, int v){

  u_vector<pair<deep_ptr<product>, int>>::iterator it = items.begin();
  u_vector<pair<deep_ptr<product>, int>>::iterator end = items.end();

  for (; it != end; it++) {
    if ((*it).first->get_name() == p->get_name() && (*it).first->get_kind() == p->get_kind()) {
      (*it).second = v;
    }
  }
}

bool receipt::presenza(const deep_ptr<product>& p) const {
  u_vector<pair<deep_ptr<product>, int>>::const_iterator cit = items.const_begin();
  u_vector<pair<deep_ptr<product>, int>>::const_iterator end = items.const_end();

  for (; cit != end; cit++) {
    if ((*cit).first->get_name() == p->get_name() && (*cit).first->get_kind() == p->get_kind()) {
      return true;
    }
  }
  return false;
}

unsigned int receipt::total_number_items() const {
  unsigned int count = 0;
  u_vector<pair<deep_ptr<product>, int>> aux = get_items();
  auto cit = aux.const_begin();
  auto end = aux.const_end();

  for (; cit != end; cit++) {
    count += (*cit).second;
  }
  return count;
}

double receipt::total_price() const {
  double price = 0;
  u_vector<pair<deep_ptr<product>, int>>::const_iterator cit = items.const_begin();
  u_vector<pair<deep_ptr<product>, int>>::const_iterator end = items.const_end();

  for (int i = 0; cit != end; cit++, i++) {
    price += total_price_line(i);
  }
  return price;
}

double receipt::total_price_line(unsigned int i) const {
  double line;
  pair<deep_ptr<product>, int> pos = items.at(i);
  line = pos.first->get_price() * pos.second;
  return line;
}

double receipt::total_taxes() const {
  double tot_taxes = 0;
  u_vector<pair<deep_ptr<product>, int>>::iterator it = items.begin();
  u_vector<pair<deep_ptr<product>, int>>::iterator end = items.end();

  for (; it != end; it++) {
    tot_taxes += (it->first->taxes() * it->second);
  }
  return tot_taxes;
}

u_vector<pair<deep_ptr<product>, int>> receipt::get_items() const { return items; }
