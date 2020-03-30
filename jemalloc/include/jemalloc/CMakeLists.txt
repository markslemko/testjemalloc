include_directories(..)
if ($<PLATFORM_ID:Windows>)
include_directories(../msvc_compat)
endif ($<PLATFORM_ID:Windows>)