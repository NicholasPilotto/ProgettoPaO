#ifndef IO_JSON_H
#define IO_JSON_H

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>
#include <QString>
#include <QTime>
#include <regex>
#include <string>

#include "Hierarchy/product.h"
#include "Utilities/deep_ptr.hpp"
#include "Utilities/u_vector.hpp"

class io_json {
 private:
  std::string __file_path;

 public:
  io_json(const std::string& = ":/data/data.json");
  static std::string dir_path;

  u_vector<deep_ptr<product>> read() const;
  bool write(const u_vector<std::pair<deep_ptr<product>, int>>&) const;
};

#endif  // IO_JSON_H
