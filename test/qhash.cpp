#include <QtTest>

#include "qjsonmapper.h"

class QHashTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:

    void deserialize()
    {
        QJsonObject object;
        object["1"] = 1.0;
        object["2"] = 2.0;
        object["3"] = 3.0;

        QHash<QString, double> data;
        qjsonmapper::ErrorInfo e;
        QVERIFY(qjsonmapper::deserialize(object, data, e));
        QCOMPARE(data.size(), 3);

        QCOMPARE(data["1"], 1.0);
        QCOMPARE(data["2"], 2.0);
        QCOMPARE(data["3"], 3.0);
    }

    void serialize()
    {
        QHash<QString, double> data;
        data.insert("1", 1.0);
        data.insert("2", 2.0);
        data.insert("3", 3.0);

        QJsonValue json;
        qjsonmapper::ErrorInfo e;
        QVERIFY(qjsonmapper::serialize(json, data, e));
        QVERIFY(json.isObject());

        QJsonObject object(json.toObject());
        QCOMPARE(object.value("1").toDouble(), 1.0);
        QCOMPARE(object.value("2").toDouble(), 2.0);
        QCOMPARE(object.value("3").toDouble(), 3.0);
    }
};

QTEST_MAIN(QHashTest)

#include "qhash.moc"
