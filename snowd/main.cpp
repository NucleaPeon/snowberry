#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include <QtCore/QCoreApplication>

#include <QtCore/QDebug>


#include "../globals.h"
#include "version.h"

/*!
 * \brief main Entry point for running the Snowberry Daemon process
 *
 * There are two components for running the daemon due to how Qt's QProcess works.
 * This is the entry point that imports QProcess and calls the snowd-runner process in a daemon mode
 * with lock file, pid, and everything else.
 *
 * QProcess needs an external command to run, so snowd-runner is the snowd QCoreApplication that handles
 * functionality, signals and slots, any DBus integrations, etc.
 *
 * \param argc
 * \param argv
 *
 * \return int
 */
int main(int argc, char *argv[])
{
    const QString VERSION = QString("%1.%2.%3.%4")
            .arg(Snowberry::SnowD::SNOWD_RELEASE_VERSION)
            .arg(Snowberry::SnowD::SNOWD_MAJOR_VERSION)
            .arg(Snowberry::SnowD::SNOWD_MINOR_VERSION)
            .arg(Snowberry::SnowD::SNOWD_PATCH_VERSION);

    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName(Snowberry::Strings::PROGRAM_NAME_SNOWD);
    QCoreApplication::setApplicationVersion(VERSION);

    QCommandLineParser parser;
    parser.setApplicationDescription(Snowberry::Strings::PROGRAM_SNOWD_DESC);
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("action", QCoreApplication::translate("action", "Action for Daemon to take: start / stop / restart / status."));

    // Process the actual command line arguments given by the user
    parser.process(app);
    const QStringList args = parser.positionalArguments();
    // Daemon d = Daemon();
    if (args.length() == 0) {
        qDebug() << "Calling daemon with no arguments, attempting start action";
        // d.start();
        return 0;
    }
    const QString actionArg = args.at(0);
    if (actionArg == "start") {
//        return d.start();
    } else if (actionArg == "status") {
//        return d.status();
    } else if (actionArg == "stop") {
//        return d.stop();
    } else if (actionArg == "restart") {
//        return d.restart();
    } else {
        qCritical("Unknown daemon action: %s", qPrintable(actionArg));
        return 1;
    }

    return 0;
}
