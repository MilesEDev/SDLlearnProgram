#include "unEndedBody.h"

unEndedBody::unEndedBody(std::string error)
{
    this->error = error;
}

std::string unEndedBody::returnError()
{
    return error;
}
