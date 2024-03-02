// ***************************************************************************************
// ***************************************************************************************
//
//      Name :      group1_system.inc
//      Authors :   Paul Robson (paul@robsons.org.uk)
//      Date :      22nd November 2023
//      Reviewed :  No
//      Purpose :   System group dispatcher.
//
// ***************************************************************************************
// ***************************************************************************************

// ***************************************************************************************
//
//                                  Group 1 (System)
//
// ***************************************************************************************

GROUP 1 System
    FUNCTION 0 Reset
        DSPReset();
    DOCUMENTATION
        Resets the messaging system and component systems.
        Normally, should not be used.

    FUNCTION 1 Timer
        *((uint32_t *)DPARAMS) = TMRRead(); // (assumes littleendian)
    DOCUMENTATION
        Deposit the value (32-bits) of the 100Hz system timer into \Param{0..3}.

    FUNCTION 2 Key Status
        i1 = *DPARAMS;
        *DPARAMS = (i1 < KBD_MAX_KEYCODE) ? KBDGetStateArray()[i1] : 0;
    DOCUMENTATION
        Deposit the state of the specified keyboard key into \Param{0}.
        The key which to query is specified in \Param{0}.

    FUNCTION 3 Basic
        MEMLoadBasic();
    DOCUMENTATION
        Loads and allows the execution of BASIC via a indirect jump through address zero.

    FUNCTION 4 Credits
        CONWriteString((char *)whoList);
    DOCUMENTATION
        Print the Neo6502 project contributors (stored in flash memory).

    FUNCTION 5 Serial Status
        SERCheckDataAvailable();
    DOCUMENTATION
        Check the serial port to see if there is a data transmission.

    FUNCTION 6 Locale
        LOCSetLocale(DPARAMS[0],DPARAMS[1]);
    DOCUMENTATION
        Set the locale code specified in \Param{0,1} as upper-case ASCII letters.
        \Param{0} takes the first letter and \Param{1} takes the second letter.
        For example:
        \begin{description}
        \item English:\MonoSp{~\Param{0}\textless-$45} ('E') and \MonoSp{\Param{1}\textless-$4E} ('N')
        \item French:\MonoSp{~~\Param{0}\textless-$46} ('F') and \MonoSp{\Param{1}\textless-$52} ('R')
        \end{description}

    FUNCTION 7 System Reset
        ResetSystem();
    DOCUMENTATION
        System Reset. This is a full hardware reset. It resets the RP2040 using the Watchdog timer, and
        this also resets the 65C02.
