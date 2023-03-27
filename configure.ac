#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_DEFUN(AC_CHECK_SYMBOL,
[AC_MSG_CHECKING([for $1 in $2])
AC_CACHE_VAL(ac_cv_func_$1,
[AC_REQUIRE_CPP()dnl
changequote(, )dnl
symbol="[^a-zA-Z_0-9]$1[^a-zA-Z_0-9]"
changequote([, ])dnl
ac_found=no
for ac_header in $2 ; do
  ac_safe=`echo "$ac_header" | sed 'y%./+-%__p_%' `
  if test $ac_found != "yes" ; then
      if eval "test \"`echo '$ac_cv_header_'$ac_safe`\" = yes"; then
            AC_EGREP_HEADER( $symbol, $ac_header, [ac_found="$ac_header"] )
      fi
  fi
done
if test "$ac_found" != "no" ; then
  AC_MSG_RESULT($ac_found)
  ifelse([$3], , :, [$3])
else
  AC_MSG_RESULT(no)
  ifelse([$4], , , [$4
])dnl
fi
])])

AC_PREREQ(2.50)
AC_INIT(QTPD_DAQ, 1.1.0, support.computing@caen.it)
AC_CONFIG_AUX_DIR([src])
AM_INIT_AUTOMAKE(QTPD_DAQ, 1.0.0)
AC_CONFIG_SRCDIR([include/Console.h])
#AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_DEFINE(LINUX,[1],"Define LINUX")
# Checks for libraries.
AC_CHECK_HEADER(CAENVMElib.h,[a=0],[a=1])
if test $a == 1; then
        AC_MSG_ERROR([
                CAENVMELib must be installed on your system.])
fi

AC_CHECK_PROG(GNUPLOT,gnuplot,"ok","no")
if test $GNUPLOT == "no"; then
        AC_MSG_WARN(
	*****************************************************************
		    GnuPLot not found QTPD_DAQ will be unable to show graphical data.
		    *****************************************************************
	)
fi

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([malloc.h stdint.h stdlib.h string.h sys/time.h sys/timeb.h termios.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_HEADER_TIME

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_SELECT_ARGTYPES
AC_CHECK_FUNCS([atexit gettimeofday memset pow select strstr])
AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_CHECK_PROG(HAVE_GNUPLOT, gnuplot, yes, no)
if test "x$HAVE_GNUPLOT" = "xno"; then
	AC_MSG_ERROR([*** Gnuplot not found])
fi
AC_OUTPUT

