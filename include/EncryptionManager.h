//
// Created by glebo on 20.04.2026.
//

#ifndef SECURE_TOURISM_DB_SYSTEM_ENCRYPTIONMANAGER_H
#define SECURE_TOURISM_DB_SYSTEM_ENCRYPTIONMANAGER_H

#include <QString>
#include <QByteArray>

class EncryptionManager {
public:
    [[nodiscard]] static QByteArray encrypt(const QString& plainText);
    [[nodiscard]] static QString decrypt(const QByteArray& encryptedData);

private:
    [[nodiscard]] static QByteArray key();
    [[nodiscard]] static QByteArray generateIV();
};

#endif // SECURE_TOURISM_DB_SYSTEM_ENCRYPTIONMANAGER_H
