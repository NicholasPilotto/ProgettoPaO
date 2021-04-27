#include "gridshow.h"

gridshow::gridshow(const u_vector<deep_ptr<product>>& _products, QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* main_layout = new QVBoxLayout();

    // ScrollArea

    product_area = new QScrollArea(this);
    product_area->setMinimumSize(550,500);
    product_area->setWidgetResizable(true);
    product_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // Mettere la griglia sul contenitore e settare il widget sulla ScrollArea

    contenitore = new QFrame();
    QGridLayout *layout = new QGridLayout();

    contenitore->setLayout(layout);
    product_area->setWidget(contenitore);

    // Inserimento Prodotti



    int r = 1, c = 1, n_ele = 3;
    u_vector<deep_ptr<product>>::iterator it = _products.begin();
    u_vector<deep_ptr<product>>::iterator end = _products.end();

    for (; it != end; it++)
    {
        QProduct *p = new QProduct(*it);

        layout->addWidget(p, r, c);

        if (c == n_ele)
        {
            r++;
            c = 1;
        }
        else
            c++;
    }

    //Aggiunta ScrollArea

    main_layout->addWidget(product_area);
    setLayout(main_layout);
}

