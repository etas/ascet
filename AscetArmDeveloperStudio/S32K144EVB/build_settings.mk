###############################################################################
## This is a configuration makefile to integrate addtional c-code to an ASCET
## project.
## All paths can be defined here absolute or relative to the current workspace
## folder.
## Following make variables can be used here to access important folders:
##    ${project_name} - contains the name of the current project (source project)
##    ${project_loc} - is absolute path to the root folder of current project.
##    ${workspace_loc} - is absolute path to the current workspace root directory.
##    ${ascet_version} - version string like V7.2.0
###############################################################################

###############################################################################
## OPTIONAL PART
###############################################################################
## Since this is just a regular makefile, all the usual make definitions like:
## * defining make variables,
## * including other makefiles
## * etc.
## are possible here.
## So let's define a path to the project,
##   where all additional c-sources, headers, libs can be found
##   we using here $(pathcnv ...) built-in function to convert that path into
##   8.3 windows short path. So there will be no blanks in that.
##   This required since following variables will define a list of entries
##   (source files, include paths, etc.) and in make a list is always space separated.

##ExternalCodeProjPath = $(pathcnv SN,$(workspace_loc)/${project_name}/HandCodeSrc)
ExternalCodeProjPath =

###############################################################################
## REQUIRED PART
###############################################################################
##  DEFINE A LIST (space separated) OF ADDITIONAL INCLUDE PATHS
##AdditionalIncPath=$(ExternalCodeProjPath)
AdditionalIncPath=

##  DEFINE A LIST (space separated) OF ADDITIONAL C SOURCE FILES TO COMPILE AND LINK THEM
##AdditionalSrcFiles=$(ExternalCodeProjPath)
AdditionalSrcFiles=

##  DEFINE A LIST (space separated) OF ADDITIONAL LIB PATHS
##  linker will use that folders to search for the libraries.
AdditionalLibPath=

##  DEFINE A LIST (space separated) OF ADDITIONAL LIBRARIES
##  usually this will be a list of base names without the lib-prefix for the
##  GNU-C compiler. (e.g.: for a library foo.a, the base name will be foo)
AdditionalLibs =
