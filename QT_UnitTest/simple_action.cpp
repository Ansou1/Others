#include <QString>
#include <QtWidgets>
#include <QtTest/QtTest>

class MSW_UnitaireTest : public QObject
{
    Q_OBJECT

public:
    MSW_UnitaireTest();

private Q_SLOTS:
    void toUpper();
    void toUpper_data();
    void testGui();
    void testGui_data();
};

void MSW_UnitaireTest::toUpper_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all lower") << "hello" << "HELLO";
    QTest::newRow("mixed")     << "Hello" << "HELLO";
    QTest::newRow("all upper") << "HELLO" << "HELLO";
}

void MSW_UnitaireTest::toUpper()
{
    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(string.toUpper(), result);

    //QString str = "Hello";
    //QCOMPARE(str.toUpper(), QString("HELLO"));

    //QVERIFY2(true, "Failure");
}

void MSW_UnitaireTest::testGui()
{
    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    QLineEdit lineEdit;

    events.simulate(&lineEdit);
    QCOMPARE(lineEdit.text(), expected);

    //QLineEdit lineEdit;
    //QTest::keyClicks(&lineEdit, "hello world");
    //QCOMPARE(lineEdit.text(), QString("hello world"));
}


void MSW_UnitaireTest::testGui_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");

    QTestEventList list1;
    list1.addKeyClick('a');
    QTest::newRow("char") << list1 << "a";

    QTestEventList list2;
    list2.addKeyClick('a');
    list2.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("there and back again") << list2 << "";
}

MSW_UnitaireTest::MSW_UnitaireTest()
{
}

QTEST_MAIN(MSW_UnitaireTest)

#include "tst_msw_unitairetest.moc"
