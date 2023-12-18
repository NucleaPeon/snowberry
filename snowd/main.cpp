#include <QDebug>
#include "../globals.h"
#include "version.h"

int main(int argc, char *argv[])
{
    qDebug() << "Launching" << Snowberry::Strings::PROGRAM_NAME_SNOWD << "version" <<
                QString("%1.%2.%3.%4")
                .arg(Snowberry::SnowD::SNOWD_RELEASE_VERSION)
                .arg(Snowberry::SnowD::SNOWD_MAJOR_VERSION)
                .arg(Snowberry::SnowD::SNOWD_MINOR_VERSION)
                .arg(Snowberry::SnowD::SNOWD_PATCH_VERSION);
	return 0;
}
