//-----------------------------------------------------
//ESTE ES EL ÚNICO FICHERO QUE HAY QUE MODIFICAR
//-----------------------------------------------------

#ifndef myStates_H
#define myStates_H

//Declaracion de las funciones
extern void FuncST1(void);
extern void FuncST2(void);
extern void FuncST3(void);
extern void FuncST4(void);

//Declaracion del nombre de ESTADOS y de EVENTOS
#define CHOCAR  	0x01
#define PARAR  	    0x02
#define DERECHA  	0x03
#define IZQUIERDA  	0x04

#define EV_Reset	0x41
#define EV_Front	0x42
#define EV_Stop		0x43
#define EV_Rear		0x44


const FSMClass::FSM_State_t FSM_State[] PROGMEM = {
  // STATE,STATE_FUNC
  {CHOCAR, FuncST1},
  {PARAR, FuncST2},
  {DERECHA, FuncST3},
  {IZQUIERDA, FuncST4},
};

const FSMClass::FSM_NextState_t FSM_NextState[] PROGMEM = {
  // STATE,EVENT,NEXT_STATE
  {CHOCAR, EV_Stop, PARAR},
  {CHOCAR, EV_Rear, DERECHA},
  {CHOCAR, EV_Front, IZQUIERDA},
  {PARAR, EV_Reset, CHOCAR},
  {DERECHA, EV_Reset, CHOCAR},
  {IZQUIERDA, EV_Reset, CHOCAR},
};

//Macros para el cálculo de los tamaños de las estructuras
//NO MODIFICAR
#define nStateFcn		    sizeof(FSM_State)/sizeof(FSMClass::FSM_State_t)
#define nStateMachine		sizeof(FSM_NextState)/sizeof(FSMClass::FSM_NextState_t)

#endif
