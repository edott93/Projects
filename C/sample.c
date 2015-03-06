void SetSerialPort() {
	char bytes_to_send[MAX_MESSAGE_LENGTH], bytes_to_send1[MAX_MESSAGE_LENGTH];
	char bytes_to_send2[MAX_MESSAGE_LENGTH];

	// Declare variables and structures
	HANDLE hSerial;
	DCB dcbSerialParams = {0};
	COMMTIMEOUTS timeouts = {0};

	// Open the highest available serial port number
   printf("Opening serial port...\n");
	hSerial = CreateFile(
				"\\\\.\\COM6", GENERIC_READ|GENERIC_WRITE, 0, NULL,
				OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );

	if (hSerial == INVALID_HANDLE_VALUE)
	{
			printf("Error\n");
			return;
	}
	else printf("OK\n");

	// Set device parameters (38400 baud, 1 start bit,
	// 1 stop bit, no parity)
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
	if (GetCommState(hSerial, &dcbSerialParams) == 0)
	{
		printf( "Error getting device state\n");
		CloseHandle(hSerial);
		return;
	}

	dcbSerialParams.BaudRate = CBR_38400;
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.StopBits = ONESTOPBIT;
	dcbSerialParams.Parity = NOPARITY;
	if(SetCommState(hSerial, &dcbSerialParams) == 0)
	{
		printf("Error setting device parameters\n");
		CloseHandle(hSerial);
		return;
	}

	// Set COM port timeout settings
	timeouts.ReadIntervalTimeout = 50; //50 originally
	timeouts.ReadTotalTimeoutConstant = 50; //50 originally
	timeouts.ReadTotalTimeoutMultiplier = 10; //10 originally
	timeouts.WriteTotalTimeoutConstant = 50; //50 originally
	timeouts.WriteTotalTimeoutMultiplier = 10; //10 originally

	if(SetCommTimeouts(hSerial, &timeouts) == 0)
	{
		printf("Error setting timeouts\n");
		CloseHandle(hSerial);
		return;
	}

	// Send specified text (remaining command line arguments)
	time_t time;
	DWORD bytes_written = 0;


	while(1) {


		GenerateRMC(time,bytes_to_send);
		GenerateGGA(time,bytes_to_send1);
		GenerateGSA(bytes_to_send2);


	    printf("Sending bytes...\n");
		if(!WriteFile(hSerial, bytes_to_send, strlen(bytes_to_send), &bytes_written, NULL))
		{
			printf("Error\n");
			CloseHandle(hSerial);
			return;
		}
		printf("%d bytes written\n", bytes_written);



		printf("Sending bytes...\n");
		if(!WriteFile(hSerial, bytes_to_send1, strlen(bytes_to_send1), &bytes_written, NULL))
		{
			printf("Error\n");
			CloseHandle(hSerial);
			return;
		}
		printf("%d bytes written\n", bytes_written);



		printf("Sending bytes...\n");
		if(!WriteFile(hSerial, bytes_to_send2, strlen(bytes_to_send2), &bytes_written, NULL))
		{
			printf("Error\n");
			CloseHandle(hSerial);
			return;
		}
		printf("%d bytes written\n", bytes_written);




		Sleep(150);

	}
	// Close serial port

	printf("Closing serial port...");
	if (CloseHandle(hSerial) == 0)
	{
		printf("Error\n");
		return;

}
