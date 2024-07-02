Proceso feriaDePollos
	definir OpcGeneral como entero;
	definir nombreCliente,dirrecionCliente como cadena ;
	definir cantidadPollos, precioPollo, totalFactura como real;
	definir cantidadVendida, totalVentasDiarias como real;
	Escribir Bienvenido a contaPlumas;
	Escribir 'Menu principal';
	Escribir ' Ingrese una opcion';
	Escribir 1.'Gestion de facturacion a clientes';
	Escribir 2.'Registrar ventas diarias';
	Escribir 3.'Salir';
	Leer OpcGeneral;
	Segun opcion  Hacer
		1:
			Escribir 'Facturacion a cliente';
			Escribir 'Ingresar nombre del cliente:';
			Leer nombreCliente;
			Escribir 'ingresar dirrecion del cliente:;
			Leer dirrecionCliente;
			Escribir 'Ingresar cantidad de pollos comprados:';
			Leer cantidadPollos;
			Escribir 'Ingresar precio por pollo:';
			Leer precioPollo;
			Escribir 'El cliente aplica a algun descuento'(SI/NO);
			Leer descuento;
		2:
			Escribir 'Registro de ventas Diarias;
			Leer cantidadVendida;
			Escribir 'ingresar cantidad de pollos vendidos' ;
			Leer precioPollo;
		3:
			Escribir 'consultar inventario';
			Leer inventarioPollos;
		4:
			Escribir 'Generar reporte diario';
		expresion:
			Escribir 'Saliendo del programa';
		De Otro Modo:
			Escribir 'Opcion no disponible;
	FinSegun
FinProceso
