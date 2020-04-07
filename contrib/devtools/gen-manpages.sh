#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

NESTCOIND=${NESTCOIND:-$BINDIR/nestcoind}
NESTCOINCLI=${NESTCOINCLI:-$BINDIR/nestcoin-cli}
NESTCOINTX=${NESTCOINTX:-$BINDIR/nestcoin-tx}
NESTCOINQT=${NESTCOINQT:-$BINDIR/qt/nestcoin-qt}

[ ! -x $NESTCOIND ] && echo "$NESTCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
PIGYVER=($($NESTCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for nestcoind if --version-string is not set,
# but has different outcomes for nestcoin-qt and nestcoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$NESTCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $NESTCOIND $NESTCOINCLI $NESTCOINTX $NESTCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${PIGYVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${PIGYVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
