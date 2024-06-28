Proceso VentasDiarias		
		Definir ventas_diarias, ganancia_diaria, total_ganancias como real;
		Definir i como entero;
		
		Escribir "Ingrese el número de ventas diarias:";
		Leer ventas_diarias;
		
		ganancia_diaria <- 0;
		total_ganancias <- 0;
		
		Para i <- 1 Hasta ventas_diarias Hacer
			Escribir "Ingrese la ganancia de la venta ", i, ":";
			Leer ganancia;
			ganancia_diaria <- ganancia_diaria + ganancia;
		FinPara
		
		total_ganancias <- ganancia_diaria;
		
		Escribir "Las ventas diarias son: ", ventas_diarias;
		Escribir "La ganancia diaria es: ", ganancia_diaria;
		Escribir "El total de ganancias es: ", total_ganancias;
		
FinProceso
