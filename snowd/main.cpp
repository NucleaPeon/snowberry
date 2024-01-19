#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include <QtCore/QCoreApplication>

#include <QtCore/QDebug>

#include "../globals.h"
#include "version.h"


int main(int argc, char *argv[])
{
    QString VERSION = QString("%1.%2.%3.%4")
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
    qDebug() << "post parser processing" << args;
    if (args.length() == 0) {
        qDebug() << "no positional args";
    } else if (args.at(0) == "status") {
        qDebug() << "Status";
    }

    return 0;
}


//#include <stdlib.h>
//#include <stdio.h>
//#include <fcntl.h>
//#include <signal.h>
//#include <unistd.h>
//#include "globaldefs.h"

//void log_message(char *filename,char *message)
//{
//    FILE *logfile;
//    logfile=fopen(filename,"a");
//    if(!logfile) return;
//    fprintf(logfile,"%s\n",message);
//    fclose(logfile);
//}


///**
//  a signal handler for the Linux signals sent to daemon process,
//  for more signals, refer to http://www.comptechdoc.org/os/linux/programming/linux_pgsignals.html
//  */
//void signal_handler(int sig)
//{
//    switch(sig) {
//    case SIGHUP:
//        log_message(LOG_FILE,"hangup signal catched");
//        break;
//    case SIGTERM:
//        log_message(LOG_FILE,"terminate signal catched");
//        break;
//    }
//}

///**
//  create background process out of the application, source code taken from: http://www.enderunix.org/docs/eng/daemon.php
//  with some minor modifications
//  */
//void init_daemon()
//{
//    int i,lfp;
//    char str[10];
//    if(getppid()==1)
//        return; /* already a daemon */
//    i=fork();
//    if (i<0)
//        exit(1); /* fork error */
//    if (i>0)
//        exit(0); /* parent exits */

//    /* child (daemon) continues */
//    setsid(); /* obtain a new process group */

//    for (i=getdtablesize();i>=0;--i)
//        close(i); /* close all descriptors */
//    i=open("/dev/null",O_RDWR); dup(i); dup(i); /* handle standart I/O */

//    umask(027); /* set newly created file permissions */

//    chdir(RUNNING_DIR); /* change running directory */
//    lfp=open(LOCK_FILE,O_RDWR|O_CREAT,0640);
//    if (lfp<0)
//        exit(1); /* can not open */
//    if (lockf(lfp,F_TLOCK,0)<0)
//        exit(0); /* can not lock */
//    /* first instance continues */
//    sprintf(str,"%d\n",getpid());
//    write(lfp,str,strlen(str)); /* record pid to lockfile */
//    signal(SIGCHLD,SIG_IGN); /* ignore child */
//    signal(SIGTSTP,SIG_IGN); /* ignore tty signals */
//    signal(SIGTTOU,SIG_IGN);
//    signal(SIGTTIN,SIG_IGN);
//    signal(SIGHUP,signal_handler); /* catch hangup signal */
//    signal(SIGTERM,signal_handler); /* catch kill signal */
//}
//int main(int argc, char *argv[])
//{
//    // first, create the daemon
//    init_daemon();
//    QCoreApplication a(argc, argv);

//    return a.exec();
//}
