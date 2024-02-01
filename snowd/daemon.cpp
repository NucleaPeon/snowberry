#include "daemon.h"


/*!
 * \brief Daemon::Daemon
 *
 * Example code:
 *
 *  int main(int argc, char *argv[])
    {
        // first, create the daemon
        Daemon d = Daemon();
        d.start();
        QCoreApplication a(argc, argv);

        return a.exec();
    }
 */
Daemon::Daemon()
{
}

int Daemon::start()
{
    this->init_daemon();
    return 0;
}

int Daemon::stop()
{
    return 0;
}

int Daemon::status()
{
    return 0;
}

int Daemon::restart()
{
    return 0;
}

/**
  create background process out of the application, source code taken from: http://www.enderunix.org/docs/eng/daemon.php
  with some minor modifications

  TODO: For windows, either figure out how to have a daemon/service for it, or simply do not compile/use snowd on windows
  and expect people to run it as a simple music player application without said functionality.
  */
void Daemon::init_daemon()
{
    if(getppid()==1)
        return; /* already a daemon */
    i=fork();
    if (i<0)
        exit(1); /* fork error */
    if (i>0)
        exit(0); /* parent exits */

    /* child (daemon) continues */
    setsid(); /* obtain a new process group */

    for (i=getdtablesize();i>=0;--i)
        close(i); /* close all descriptors */
    i=open("/dev/null",O_RDWR); dup(i); dup(i); /* handle standard I/O */

    umask(027); /* set newly created file permissions */

    //log_message(logfilename, "Changing directory"); //.arg(QDir::currentPath()));
    QDir::setCurrent(QDir::currentPath());
    // chdir(RUNNING_DIR); /* change running directory */
    this->lockfile = new QLockFile(lockfilename);
    // lfp=open(LOCK_FILE,O_RDWR|O_CREAT,0640);
    if (! this->lockfile->isLocked()) {
        // Not locked by this lockfile
        qFatal("Could not establish a lock file");
        exit(0);
    }
    /* first instance continues */
    int pid = getpid();
    QFile file(this->pidfilename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(QString(pid).toLatin1());
        file.close();
    }
    signal(SIGCHLD,SIG_IGN); /* ignore child */
    signal(SIGTSTP,SIG_IGN); /* ignore tty signals */
    signal(SIGTTOU,SIG_IGN);
    signal(SIGTTIN,SIG_IGN);
    //signal(SIGHUP, this->signal_handler); /* catch hangup signal */
    //signal(SIGTERM, this->signal_handler); /* catch kill signal */

    //log_message(logfilename, "Daemon initialization complete.");
}


/**
  a signal handler for the Linux signals sent to daemon process,
  for more signals, refer to http://www.comptechdoc.org/os/linux/programming/linux_pgsignals.html
  */
void signal_handler(int sig)
{
//    switch(sig) {
//    case SIGHUP:
//        this->log_message(logfilename,"hangup signal caught");
//        break;
//    case SIGTERM:
//        this->log_message(logfilename,"terminate signal caught");
//        break;
//    }
}

void log_message(QString filename,QString message)
{
    QFile file(filename);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        file.write(message.toLatin1());
        file.close();
    }
}
