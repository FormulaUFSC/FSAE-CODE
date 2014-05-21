#ifndef CFW11_h
#define CFW11_h

class CFW11{
 public:
     enum Inversor_State{
        Ready=0, Run=1, SubVoltage=2,
        Fail=3, AutoAdjust=4,
        Configuration=5
     };
     int velocity_reference_rpm;
     int velocity_motor_rpm;
     int current_motor_A;
     int voltage_dc_V;
     Inversor_State inversor_state;
     int voltage_motor_V;
     int torque_motor_p100;
     int power_motor_kW;
     int cos_phi_motor;
     int digital_input_1_8;
     int temp_igbt_U, temp_igbt_V, temp_igbt_W;
     int temp_inversor;
     int temp_air;
  CFW11(void);
  void setup();
  void loop();
  static int priority;
};

#endif
