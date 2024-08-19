#ifndef REQUEST_H
#define REQUEST_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QIODevice>
#include <QUrl>
#include <QObject>
#include <QDebug>
extern QString path;

class Request : public QObject {
    Q_OBJECT

public:
    explicit Request(QObject *parent = nullptr);

    static QNetworkAccessManager* networkManager;

    static QJsonDocument get(const QString& url, const QMap<QString, QString>& headers = {});
    static QJsonDocument post(const QString& url, const QJsonDocument& jsonBody, const QMap<QString, QString>& headers = {});
};

#endif // REQUEST_H
