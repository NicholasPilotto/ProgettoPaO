#include "io_json.h"

io_json::io_json(const std::string& path) : __file_path(path) {}

u_vector<deep_ptr<product>> io_json::read() {
  QFile file_obj(QString::fromStdString(__file_path));
  if (!file_obj.open(QIODevice::ReadOnly)) {
    qDebug() << "Failed to open ";
    throw std::exception();
  }

  // step 2
  QTextStream file_text(&file_obj);
  QString json_string;
  json_string = file_text.readAll();
  file_obj.close();
  QByteArray json_bytes = json_string.toLocal8Bit();

  // step 3
  auto json_doc = QJsonDocument::fromJson(json_bytes);

  if (json_doc.isNull()) {
    qDebug() << "Failed to create JSON doc.";
    throw std::exception();
  }
  if (!json_doc.isObject()) {
    qDebug() << "JSON is not an object.";
    throw std::exception();
  }

  QJsonObject json_obj = json_doc.object();

  if (json_obj.isEmpty()) {
    qDebug() << "JSON object is empty.";
    throw std::exception();
  }

  QVariantMap tmp = json_obj.toVariantMap();

  QMap<QString, QVariant> map = tmp["elements"].toMap();

  QMap<QString, QVariant>::iterator it = map.begin();
  QMap<QString, QVariant>::iterator end = map.end();

  u_vector<deep_ptr<product>> result;

  for (; it != end; it++) {
    QMap<QString, QVariant> m = (*it).toMap();
    result.push_back(deep_ptr<product>(product::unserialize(m)));
  }

  return result;
}
