#include <QtCore/QString>
#include "../version.h"
#include "../../globals.h"

int main(int argc, char *argv[])
{
    const QString VERSION = QString("%1.%2.%3.%4")
            .arg(Snowberry::SnowD::SNOWD_RELEASE_VERSION)
            .arg(Snowberry::SnowD::SNOWD_MAJOR_VERSION)
            .arg(Snowberry::SnowD::SNOWD_MINOR_VERSION)
            .arg(Snowberry::SnowD::SNOWD_PATCH_VERSION);

    return 0;
}
