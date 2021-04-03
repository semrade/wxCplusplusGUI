

/* ---------------------------------------------------------------------- */
#ifndef TSERIAL_H
#define TSERIAL_H
#include <iostream>
#include <stdio.h>
#include <windows.h>

#include <list>
#include <map>

using namespace std;

enum serial_parity  { spNONE, spODD, spEVEN };


/* -------------------------------------------------------------------- */
/* -----------------------------  Tserial  ---------------------------- */
/* -------------------------------------------------------------------- */
class Tserial
{
	// -------------------------------------------------------- //
public:
	char                        port[10];                      // port name "com1",...
	list<string>                ComPorts;
	list<map<string,string>>    ComPortsDes;
	unsigned                    rate;                          // baudrate
	serial_parity               parityMode;
	HANDLE                      serial_handle;                 // ...

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// .................. EXTERNAL VIEW .............
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public:
	Tserial();
	~Tserial();
	int           connect          (char *port_arg, int rate_arg, serial_parity parity_arg);
	void          sendChar         (char c);
	void          sendArray        (char *buffer, int len);
	char          getChar          (void);
	int           getArray         (char *buffer, int len);
	int           getNbrOfBytes    (void);
	void          disconnect       (void);
	bool          SelectComPort    (void);
	bool          isopen           (void);
};
/* -------------------------------------------------------------------- */

#endif


