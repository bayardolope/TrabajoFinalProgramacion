Proceso FacturacionCliente
	definir nombreCliente, direccionCliente Como Caracter;
	definir precioProducto, cantidadProducto, totalpagar como real;
	escribir "Ingresar el nombre del cliente: ";
	leer nombreCliente;
	escribir "Ingresar la direccion del cliente: ";
	leer direccionCliente;
	Escribir "Ingresar cantidad de producto adquirido: ";
	leer cantidadProducto;
	Escribir "Ingresar el precio por producto: ";
	Leer precioProducto;
	totalpagar <- cantidadProducto * precioProducto;
	Escribir  nombreCliente;
	Escribir direccionCliente;
	Escribir cantidadProducto;
	Escribir totalpagar;
	
	
FinProceso
