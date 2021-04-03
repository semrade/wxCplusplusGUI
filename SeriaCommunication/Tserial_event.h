
#ifndef TSERIAL_EVENT_H
#define TSERIAL_EVENT_H

#include <stdio.h>
#include <windows.h>

#define SERIAL_PARITY_NONE 0
#define SERIAL_PARITY_ODD  1
#define SERIAL_PARITY_EVEN 2

#define SERIAL_CONNECTED         0
#define SERIAL_DISCONNECTED      1
#define SERIAL_DATA_SENT         2
#define SERIAL_DATA_ARRIVAL      3
#define SERIAL_RING              4
#define SERIAL_CD_ON             5
#define SERIAL_CD_OFF            6

typedef unsigned long uint32;
typedef void (*type_myCallBack) (uint32 object, uint32 event);

#ifndef __BORLANDC__
#define bool  BOOL
#define true  TRUE
#define false FALSE
#endif


#define SERIAL_SIGNAL_NBR 7         // number of events in the thread
#define SERIAL_MAX_RX     256       // Input buffer max size
#define SERIAL_MAX_TX     256       // output buffer max size


/* -------------------------------------------------------------------- */
/* -----------------------------  Tserial  ---------------------------- */
/* -------------------------------------------------------------------- */
class Tserial_event
{
	// -------------------------------------------------------- //
protected:
	bool          ready;
	bool          check_modem;
	char          port[10];                          // port name "com1",...
	int           rate;                              // baudrate
	int           parityMode;

	HANDLE        serial_events[SERIAL_SIGNAL_NBR];  // events to wait on
	unsigned int  threadid;                          // ...
	HANDLE        serial_handle;                     // ...
	HANDLE        thread_handle;                     // ...
	OVERLAPPED    ovReader;                          // Overlapped structure for ReadFile
	OVERLAPPED    ovWriter;                          // Overlapped structure for WriteFile
	OVERLAPPED    ovWaitEvent;                       // Overlapped structure for WaitCommEvent
	char          tx_in_progress;                    // BOOL indicating if a WriteFile is
	// in progress
	char          rx_in_progress;                    // BOOL indicating if a ReadFile is
	// in progress
	char          WaitCommEventInProgress;
	char          rxBuffer[SERIAL_MAX_RX];
	int           max_rx_size;
	int           received_size;
	char          txBuffer[SERIAL_MAX_TX];
	int           tx_size;
	DWORD         dwCommEvent;                       // to store the result of the wait

	type_myCallBack manager;

	// ............................................................
	void          OnCharArrival    (char c);
	void          OnEvent          (unsigned long events);


	// ++++++++++++++++++++++++++++++++++++++++++++++
	// .................. EXTERNAL VIEW .............
	// ++++++++++++++++++++++++++++++++++++++++++++++
public:
	void         *owner;                // do what you want with this
	void          run              (void);
	Tserial_event();
	~Tserial_event();
	int           connect          (char *port, int rate, int parity,
                                    char ByteSize, bool modem_events);

	void          setManager       (type_myCallBack manager);
	void          setRxSize        (int size);
	void          sendData         (char *buffer, int size);
	int           getNbrOfBytes    (void);
	int           getDataInSize    (void);
	char *        getDataInBuffer  (void);
	void          dataHasBeenRead  (void);
	void          disconnect       (void);
};
/* -------------------------------------------------------------------- */

#endif


