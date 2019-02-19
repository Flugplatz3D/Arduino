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
#define STATE1  	0x01
#define STATE2  	0x02
#define STATE3  	0x03
#define STATE4  	0x04

#define EV_Reset	0x41
#define EV_Front	0x42
#define EV_Stop		0x43
#define EV_Rear		0x44


const FSMClass::FSM_State_t FSM_State[] PROGMEM = {
  // STATE,STATE_FUNC
  {STATE1, FuncST1},
  {STATE2, FuncST2},
  {STATE3, FuncST3},
  {STATE4, FuncST4},
};

const FSMClass::FSM_NextState_t FSM_NextState[] PROGMEM = {
  // STATE,EVENT,NEXT_STATE
  {STATE1, EV_Stop, STATE2},
  {STATE1, EV_Rear, STATE3},
  {STATE1, EV_Front, STATE4},
  {STATE2, EV_Reset, STATE1},
  {STATE3, EV_Reset, STATE1},
  {STATE4, EV_Reset, STATE1},
};

//Macros para el cálculo de los tamaños de las estructuras
//NO MODIFICAR
#define nStateFcn		    sizeof(FSM_State)/sizeof(FSMClass::FSM_State_t)
#define nStateMachine		sizeof(FSM_NextState)/sizeof(FSMClass::FSM_NextState_t)

#endif

