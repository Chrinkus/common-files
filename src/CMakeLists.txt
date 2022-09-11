set(sources
        "cf_path.c"
)

set(headers
        "cf_defs.h"
        "cf_path.h"
)

add_library(${LIB_NAME} "${sources}")

set_target_properties(${LIB_NAME} PROPERTIES
        VERSION         ${PROJECT_VERSION}
        SOVERSION       ${PROJECT_VERSION_MAJOR}
        PUBLIC_HEADER   "${headers}"
)

