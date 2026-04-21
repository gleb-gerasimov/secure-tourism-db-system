//
// Created by glebo on 20.04.2026.
//

#ifndef SECURE_TOURISM_DB_SYSTEM_SEARCHMANAGER_H
#define SECURE_TOURISM_DB_SYSTEM_SEARCHMANAGER_H
#include "Record.h"
#include "Database.h"
#include "EncryptionManager.h"


class SearchManager {
public:
    SearchManager(Database* database, EncryptionManager* encryptionManager);

    [[nodiscard]] QVector<Record> findByDateRange(const QString& start, const QString& end) const;
    [[nodiscard]] QVector<Record> findByType(const QString& type) const;
    [[nodiscard]] QVector<Record> findByCountry(const QString& country) const;

private:
    Database* m_database;
    EncryptionManager* m_encryptionManager;
};



#endif //SECURE_TOURISM_DB_SYSTEM_SEARCHMANAGER_H
