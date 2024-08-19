#include "request.h"
#include <QEventLoop>
#include <QDebug>

QString path = "http://127.0.0.1:3000/";

// Initialize the static member
QNetworkAccessManager* Request::networkManager = new QNetworkAccessManager();

Request::Request(QObject *parent) : QObject(parent) {
    // Additional initialization if needed
}

QJsonDocument Request::get(const QString& url, const QMap<QString, QString>& headers) {
    QUrl qUrl(url);
    QNetworkRequest request(qUrl);

    // Set custom headers
    for (auto it = headers.begin(); it != headers.end(); ++it) {
        request.setRawHeader(it.key().toUtf8(), it.value().toUtf8());
    }

    QNetworkReply* reply = networkManager->get(request);

    // Use QEventLoop to wait for the reply
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();  // Wait until the reply is finished

    // Process the reply
    QJsonDocument jsonDoc;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        jsonDoc = QJsonDocument::fromJson(responseData);
    } else {
        QJsonObject errorObject;
        errorObject["error"] = "not connected";
        errorObject["error_message"] = reply->errorString();
        jsonDoc = QJsonDocument(errorObject);

    }

    reply->deleteLater();
    return jsonDoc;
}

QJsonDocument Request::post(const QString& url, const QJsonDocument& jsonBody, const QMap<QString, QString>& headers) {
    QUrl qUrl(url);
    QNetworkRequest request(qUrl);

    // Set custom headers
    for (auto it = headers.begin(); it != headers.end(); ++it) {
        request.setRawHeader(it.key().toUtf8(), it.value().toUtf8());
    }

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = networkManager->post(request, jsonBody.toJson());

    // Use QEventLoop to wait for the reply
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();  // Wait until the reply is finished

    // Process the reply
    QByteArray responseData = reply->readAll();
    QJsonDocument jsonDoc;

    if (reply->error() == QNetworkReply::NoError) {
        jsonDoc = QJsonDocument::fromJson(responseData);
    }
    else {
        qWarning() << "Failed to send data:" << reply->errorString();
        qWarning() << "Response body:" << responseData;

        // Attempt to parse the response body as JSON, if possible
        jsonDoc = QJsonDocument::fromJson(responseData);
    }

    reply->deleteLater();
    return jsonDoc;
}

