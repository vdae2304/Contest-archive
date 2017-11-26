#include "caracol.h"

int velocidad() {
    int v_min = 1, v_max = 1000000;
    int t = 1, t_retorno;
    bool retorno = false;

    while (v_min < v_max) {
        int v = (v_min + v_max) / 2;
        int d = retorno ? v * (2*t_retorno - t) : v * t;
        int q = pregunta(d);

        switch (q) {
            case -3: return v; //La busqueda binaria es lo suficientemente rapida para no llegar a este caso
            case -2:
                if (!retorno) { //Primera vez que se retorna
                    retorno = true;
                    t_retorno = t - 1;
                }
                else
                    v_max = v - 1;
                break;
            case -1:
                v_max = v - 1; //Es mas lento
                break;
            case 0:
                if (!retorno) {
                    q = pregunta(d); //Preguntamos otra vez
                    if (q == -2 || q == 2 || q == 3) { //Retorn�
                        t_retorno = t + 1;
                        while (pregunta(d) != -3) //Preguntamos hasta que regrese al inicio
                            t_retorno++;
                        return d / (t_retorno - t);
                    }
                }
                return v;
            case 1:
                v_min = v + 1; //Es mas rapido
                break;
            case 2:
                if (!retorno) { //Primera vez que se regresa
                    retorno = true;
                    t_retorno = t - 1;
                }
                else
                    v_max = v - 1;
                break;
            case 3:
                if (!retorno) {
                    retorno = true; //Se regreso
                    t_retorno = t - 1;
                }
                else
                    v_min = v + 1; //Es mas rapido
        }
        t++;
    }

	return v_min;
}
