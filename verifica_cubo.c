#include "cubo.h"

bool verificar_cubo_resolvido(const Cubo *cubo)  {
    for (int f = 0; f < NUM_FACES; f++) {
        char cor_ref = cubo->faces[f][0][0];
        
        for (int i = 0; i < NUM_LINCOL; i++) {
            for (int j = 0; j < NUM_LINCOL; j++) {
                if (cubo->faces[f][i][j] != cor_ref) {
                    return false;
                }
            }
        }
    }
    return true;
}
/* bool retorna valores booleanos vdd ou falso*/