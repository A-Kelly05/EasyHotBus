SubProceso Bus
	Definir opc Como Entero;
	Definir idBus,placaBus,motorBus,trasmisionBus,llantasBus,trabajosBus Como Caracter;
	Definir anoBus,capacidadBus Como Entero;
	Definir kmBus Como Real;
	Repetir
		Escribir '------Información------';
		Escribir '1.Agregar Bus';
		Escribir '2.Editar Bus';
		Escribir '3.Eliminar Bus';
		Escribir '4.Mostar Bus';
		Escribir '5.Mantenimiento Bus';
		Escribir '6.Salir';
		Escribir 'Digite una opcion: ', Sin Saltar;
		Leer opc;
		Segun opc  Hacer
			1:
				Escribir 'Agregar Bus';
				Escribir '# Bus: ', Sin Saltar;
				Leer idBus;
				Escribir 'Placa Bus: ', Sin Saltar;
				Leer placaBus;
				Escribir 'Año Bus: ', Sin Saltar;
				Leer anoBus;
				Escribir 'Capacidad Bus: ', Sin Saltar;
				Leer capacidadBus;
				Escribir 'Motor Bus: ', Sin Saltar;
				Leer motorBus;
				Escribir 'Trasmision Bus: ', Sin Saltar;
				Leer trasmisionBus;
				Escribir 'Llantas Bus: ', Sin Saltar;
				Leer llantasBus;
				Escribir 'Trabajos Bus: ', Sin Saltar;
				Leer trabajosBus;
				Escribir 'Km recorrido: ', Sin Saltar;
				Leer kmBus;
				Escribir 'Listo ha sido registrado';
				Esperar Tecla;
			2:
				Escribir 'Editar Bus';
				Escribir '# Bus: ', Sin Saltar;
				Leer idBus;
				Escribir 'Placa Bus: ', Sin Saltar;
				Leer placaBus;
				Escribir 'Año Bus: ', Sin Saltar;
				Leer anoBus;
				Escribir 'Capacidad Bus: ', Sin Saltar;
				Leer capacidadBus;
				Escribir 'Motor Bus: ', Sin Saltar;
				Leer motorBus;
				Escribir 'Trasmision Bus: ', Sin Saltar;
				Leer trasmisionBus;
				Escribir 'Llantas Bus: ', Sin Saltar;
				Leer llantasBus;
				Escribir 'Trabajos Bus: ', Sin Saltar;
				Leer trabajosBus;
				Escribir 'Km recorrido: ', Sin Saltar;
				Leer kmBus;
				Escribir 'Listo ha sido cambiado';
				Esperar Tecla;
			3:
				Escribir 'Bienvenido a Eliminar Bus', Sin Saltar;
				Escribir 'Deseas eliminar el Bus: (Si / no)';
				Leer Desicion;
				Si Desicion='si' Entonces
					idBus <- ' ';
					placaBus <- ' ';
					anoBus <- 0;
					capacidadBus <- 0;
					LmotorBus <- ' ';
					trasmisionBus <- ' ';
					llantasBus <- ' ';
					trabajosBus <- ' ';
					kmBus <- 0.00;
					Escribir 'Listo ha sido eliminado';
				FinSi
				Esperar Tecla;
			4:
				Escribir '# Bus: ',idBus;
				Escribir 'Placa Bus: ',placaBus;
				Escribir 'Year Bus: ',anoBus;
				Escribir 'Capacidad Bus: ',capacidadBus;
				Escribir 'Motor Bus: ',motorBus;
				Escribir 'Trasmision Bus: ',trasmisionBus;
				Escribir 'Llantas Bus: ',llantasBus;
				Escribir 'Trabajos Bus: ',trabajosBus;
				Escribir 'Km recorrido: ',kmBus;
				Esperar Tecla;
			5:
				Escribir 'Mantenimiento de Buses';
				Escribir 'Cambio de Aceite: 5,000 kms';
				Escribir 'Cambio de Filtro de Aceite: 5,000 kms';
				Escribir 'Cambio de Filtro de Combustible: 10,000 kms';
				Escribir 'Cambio de Filtro de Aire: 40,000 kms';
				Escribir 'Engrase General: 2,000 kms';
				Escribir 'Engrase de Patentes: 40,000 kms';
				Escribir 'Ajuste de Embrague: 7,200 kms';
				Escribir 'Mantenimiento Sistema Electrico: 25,000 kms';
				Escribir 'Scanner al Sistema Electronico: 65,000 kms';
				Escribir 'Rotacion de Llantas: 30,000 kms';
				Escribir 'Cambio de Llantas: 75,000 kms';
				Escribir 'Niveles de Aceite de Diferencial: 14,400 kms';
				Escribir 'Niveles de Aceite de Caja/Transmision: 14,400 kms';
				Escribir 'Revisión de Yugos y Cruz Cardánica: 4,000 kms';
				Escribir 'Fricciones: 28,800 kms';
				Escribir 'Alineacion y Balanceo: 57,600 kms';
				Escribir 'Imprevisto al motor: 7,200 kms';
				Escribir 'Coste total de Mantenimiento: C$45,096.60';
				Esperar Tecla;
			6:
				Escribir 'Saliendo...';
			De Otro Modo:
				Escribir 'Opcion no disponible';
		FinSegun
	Hasta Que opc=6
FinSubProceso

SubProceso Ticket
	Definir cantidad,opcT Como Entero;
	Definir origen,destino,fecha,horarioF,idF,idT Como Caracter;
	Definir Precio,total Como Real;
	Repetir
		Escribir '------Ticket------';
		Escribir '1. Agregar Destino';
		Escribir '2. Editar Destino';
		Escribir '3. Mostrar Destino';
		Escribir '4. Agrear Factura';
		Escribir '5. Imprimir Factura';
		Escribir '6.Salir';
		Escribir 'Digite una opcion: ', Sin Saltar;
		Leer opcT;
		Segun opcT  Hacer
			1:
				Escribir 'Agregar Destino';
				Escribir 'id Destino ', Sin Saltar;
				Leer idT;
				Escribir 'Origen: ', Sin Saltar;
				Leer origen;
				Escribir 'Destino: ', Sin Saltar;
				Leer destino;
				Escribir 'Precio: ', Sin Saltar;
				Leer Precio;
				Escribir 'Listo Destino ha sido registrado';
				Esperar Tecla;
			2:
				Escribir 'Editar Destino';
				Escribir 'id Destino ', Sin Saltar;
				Leer idT;
				Escribir 'Origen: ', Sin Saltar;
				Leer origen;
				Escribir 'Destino: ', Sin Saltar;
				Leer destino;
				Escribir 'Precio: ', Sin Saltar;
				Leer Precio;
				Escribir 'Listo Destino ha sido editado';
				Esperar Tecla;
			3:
				Escribir 'Mostar Destino';
				Escribir 'id Destino ',idT;
				Escribir 'Origen: ',origen;
				Escribir 'Destino: ',destino;
				Escribir 'Precio: ',Precio;
				Esperar Tecla;
			4:
				Escribir 'Agregar Factura';
				Escribir 'id Factura ', Sin Saltar;
				Leer idF;
				Escribir 'Fecha ', Sin Saltar;
				Leer fecha;
				Escribir 'Horario ', Sin Saltar;
				Leer horarioF;
				Escribir 'Origen: ',origen;
				Escribir 'Destino: ',destino;
				Escribir 'Cantidad Ticket', Sin Saltar;
				Leer cantidad;
				Escribir 'Precio: ',Precio;
				total <- cantidad*Precio;
				Escribir 'Total: ',total;
				Escribir 'Listo Factura ha sido registrada';
				Esperar Tecla;
			5:
				Escribir 'Mostrar Factura';
				Escribir 'id Factura ',idF;
				Escribir 'Fecha ',fecha;
				Escribir 'Horario ',horarioF;
				Escribir 'Origen: ',origen;
				Escribir 'Destino: ',destino;
				Escribir 'Cantidad Ticket',cantidad;
				Escribir 'Precio: ',Precio;
				Escribir 'Total: ',total;
				Esperar Tecla;
			6:
				Escribir 'Saliendo....';
			De Otro Modo:
				Escribir 'Opción Incorrecta';
		FinSegun
	Hasta Que opcT=6
FinSubProceso

SubProceso Usuario
	Definir ID,Nombre,Apellido,Cedula,FechaNac,Cargo,Desicion Como Caracter;
	Definir BusTrabajo,OpcUsuario Como Entero;
	Definir Salario Como Real;
	Repetir
		Escribir 'Bienvenido al apartado de Usuario';
		Escribir '1. Agregar Usuario';
		Escribir '2. Editar Usuario';
		Escribir '3. Eliminar Usuario';
		Escribir '4. Mostar Usuario';
		Escribir '5. Salir';
		Escribir 'Digitar la opcion a usar: ', Sin Saltar;
		Leer OpcUsuario;
		Segun OpcUsuario  Hacer
			1:
				Escribir 'Bienvenido a Agregar Usuario';
				Escribir 'ID: ', Sin Saltar;
				Leer ID;
				Escribir 'Nombre: ', Sin Saltar;
				Leer Nombre;
				Escribir 'Apellido: ', Sin Saltar;
				Leer Apellido;
				Escribir 'Fecha Nac. (formato:dd/mm/yyyy): ', Sin Saltar;
				Leer FechaNac;
				Escribir 'Cedula: ', Sin Saltar;
				Leer Cedula;
				Escribir 'Bus donde se trabaja David#: ', Sin Saltar;
				Leer BusTrabajo;
				Escribir 'Cargo que desempeña: ', Sin Saltar;
				Leer Cargo;
				Escribir 'Salario que desembolza: C$ ', Sin Saltar;
				Leer Salario;
				Escribir 'Listo, Ya ha sido registrado';
			2:
				Escribir 'Bienvenido a Editar Usuario';
				Escribir 'ID: ', Sin Saltar;
				Leer ID;
				Escribir 'Nombre: ', Sin Saltar;
				Leer Nombre;
				Escribir 'Apellido: ', Sin Saltar;
				Leer Apellido;
				Escribir 'Fecha Nac. (formato:dd/mm/yyyy): ', Sin Saltar;
				Leer FechaNac;
				Escribir 'Cedula: ', Sin Saltar;
				Leer Cedula;
				Escribir 'Bus donde se trabaja David#: ', Sin Saltar;
				Leer BusTrabajo;
				Escribir 'Cargo que desempeña: ', Sin Saltar;
				Leer Cargo;
				Escribir 'Salario que desembolza: C$ ', Sin Saltar;
				Leer Salario;
				Escribir 'Listo, Ya ha sido Editado';
			3:
				Escribir 'Bienvenido a Eliminar Usuario', Sin Saltar;
				Escribir 'Deseas eliminar el Usuario: (Si / no)';
				Leer Desicion;
				Si Desicion='si' Entonces
					ID <- '';
					Nombre <- '';
					Apellido <- '';
					Cedula <- '';
					FechaNac <- '';
					Cargo <- '';
					BusTrabajo <- 0;
					Salario <- 0.00;
					Escribir 'El usuario ha sido eliminado correctamente';
				FinSi
			4:
				Escribir 'ID: ',ID;
				Escribir 'Nombre: ',Nombre;
				Escribir 'Apellido: ',Apellido;
				Escribir 'Fecha Nac: ',FechaNac;
				Escribir 'Cedula: ',Cedula;
				Escribir 'Bus donde se trabaja David#: ',BusTrabajo;
				Escribir 'Cargo que desempeña: ',Cargo;
				Escribir 'Salario que desembolza: C$ ',Salario;
			5:
				Escribir 'Saliendo....';
			De Otro Modo:
				Escribir 'Digite una opcion correcta';
		FinSegun
	Hasta Que OpcUsuario=5
FinSubProceso

SubProceso Horario
	Definir OpcHorario Como Entero;
	Definir Idhorario,busID,origen,destino,hora_origen,hora_destino Como Caracter;
	Repetir
		Escribir 'Bienvenido al apartado de Horario';
		Escribir '1. Agregar Itinerario';
		Escribir '2. Editar Itinerario';
		Escribir '3. Eliminar Itinerario';
		Escribir '4. Mostar Itinerario';
		Escribir '5. Salir';
		Escribir 'Digitar la opcion a usar: ', Sin Saltar;
		Leer OpcHorario;
		Segun OpcHorario  Hacer
			1:
				Escribir 'Bienvenido a Agregar Horario';
				Escribir 'ID Horario: ', Sin Saltar;
				Leer Idhorario;
				Escribir 'ID bus: ', Sin Saltar;
				Leer busID;
				Escribir 'Origen: ', Sin Saltar;
				Leer origen;
				Escribir 'Destino): ', Sin Saltar;
				Leer destino;
				Escribir 'Hora Salida: ', Sin Saltar;
				Leer hora_origen;
				Escribir 'Hora Llegada: ', Sin Saltar;
				Leer hora_destino;
				Escribir 'Listo, Ya ha sido registrado';
				Esperar Tecla;
			2:
				Escribir 'Bienvenido a Editar Horario';
				Escribir 'ID Horario: ', Sin Saltar;
				Leer Idhorario;
				Escribir 'ID bus: ', Sin Saltar;
				Leer busID;
				Escribir 'Origen: ', Sin Saltar;
				Leer origen;
				Escribir 'Destino): ', Sin Saltar;
				Leer destino;
				Escribir 'Hora Salida: ', Sin Saltar;
				Leer hora_origen;
				Escribir 'Hora Llegada: ', Sin Saltar;
				Leer hora_destino;
				Escribir 'Listo, Ya ha sido modificado';
				Esperar Tecla;
			3:
				Escribir 'Bienvenido a Eliminar Horario', Sin Saltar;
				Escribir 'Deseas eliminar el Horario: (Si / no)';
				Leer Desicion;
				Si Desicion='si' Entonces
					Idhorario <- '';
					busID <- '';
					origen <- '';
					destino <- '';
					hora_origen <- '';
					hora_destino <- '';
					Escribir 'El horario ha sido eliminado correctamente';
				FinSi
				Esperar Tecla;
			4:
				Escribir 'Mostrar Horario';
				Escribir 'ID Horario: ',Idhorario;
				Escribir 'ID bus: ',busID;
				Escribir 'Origen: ',origen;
				Escribir 'Destino): ',destino;
				Escribir 'Hora Salida: ',hora_origen;
				Escribir 'Hora Llegada: ',hora_destino;
				Esperar Tecla;
			5:
				Escribir 'Saliendo....';
			De Otro Modo:
				Escribir 'Digite una opcion correcta';
		FinSegun
	Hasta Que OpcHorario=5
FinSubProceso

Proceso Transporte_David
	Definir OpcGeneral Como Entero;
	Escribir 'Bienvenido a Easy Transorte';
	Escribir ' Elige una de las siguientes opciones: ';
	Escribir '1. Información';
	Escribir '2. Ticket';
	Escribir '3. Horario';
	Escribir '4. Usuario';
	Escribir '5. Salir';
	Escribir 'Digite su opcion: ', Sin Saltar;
	Leer OpcGeneral;
	Segun OpcGeneral  Hacer
		1:
			Bus;
		2:
			Ticket;
		3:
			Horario;
		4:
			Usuario;
		De Otro Modo:
			Escribir 'Volver a Digitar otra opcion';
	FinSegun
FinProceso
