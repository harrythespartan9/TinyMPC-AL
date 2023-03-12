#include "tiny_struct.h"
#include "slap/slap.h"

void tiny_DynamicsLti(Matrix* xn, const Matrix x, const Matrix u,
                           const tiny_LtiModel model);

void tiny_DynamicsLtv(Matrix* xn, const Matrix x, const Matrix u,
                           const tiny_LtvModel model, const int k);

enum slap_ErrorCode tiny_ForwardPassLtv(
    Matrix* X, Matrix* U, const tiny_ProblemData prob, 
    const tiny_LtvModel model);

enum slap_ErrorCode tiny_ForwardPassLti(Matrix* X, Matrix* U,
                                        const tiny_ProblemData prob,
                                        const tiny_LtiModel model);    