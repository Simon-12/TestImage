#include <QDebug>
#include <QFile>
#include <QImage>
#include <QImageWriter>
#include <QImageReader>


int main()
{
    QImage image("../TestImage/Penguins.jpg");      // Source
    QImageWriter writer("../TestImage/Test.jpg");   // Target

    // Check if the image support embedding of text or comments
    if(writer.supportsOption(QImageIOHandler::Description))
    {
        writer.setText("Artist", "Chura Zlone");

        if(!writer.write(image))
            qDebug() << "Can not write image";
    }
    else
        qDebug() << "Comment not supported";

    // Test key
    QImage test("../TestImage/Test.jpg");
    qDebug() << test.text("Artist");

    // Test reader
    QImageReader reader("../TestImage/Penguins.jpg");
    qDebug() << reader.textKeys();


    return 0;
}
