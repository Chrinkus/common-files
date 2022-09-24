set(sources
        "cf_path.c"
        "cf_home.c"
        "cf_config.c"
)

set(headers
        "cf.h"
        "cf_defs.h"
        "cf_path.h"
)

add_library(${LIB_NAME} "${sources}")

set_target_properties(${LIB_NAME} PROPERTIES
        VERSION         ${PROJECT_VERSION}
        SOVERSION       ${PROJECT_VERSION_MAJOR}
        PUBLIC_HEADER   "${headers}"
)

