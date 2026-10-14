#! /bin/sh

echo "Pulsar IRC Services"
echo ""
echo "Instalacion de los servicios IRC para TeamIRC..."
echo ""

if [ x"$1" = x ]
then
        echo "Uso $0 <path>"
	echo "Ejemplo de Path: /home/user/services"
	echo " "
        exit 1
fi

echo Configurando Servicios
./configure --program=services --bindest=$1 --datdest=$1

echo ""
exit 0
