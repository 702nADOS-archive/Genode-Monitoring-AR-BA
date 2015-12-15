#include <base/env.h>
#include <base/printf.h>
#include <sensordir_session/client.h>
#include <sensordir_session/connection.h>
#include <dataspace/client.h>
#include <base/ipc.h>
#include <timer_session/connection.h>
#include <sensors/scalar.h>
#include <client.h>

using namespace Genode;

int main(void)
{
	Timer::Connection t;

	t.msleep(1000);

	printf("Hello from the scalar demo.\n");

	ferret_scalar_t * s1 = NULL, * s2 = NULL, * s3 = NULL, * s4 = NULL;

	ferret_create(10, 1, 0, FERRET_SCALAR, 0, 0, s1);

	ferret_create(20, 1, 0, FERRET_SCALAR, 0, 0, s2);

	ferret_create(30, 1, 0, FERRET_SCALAR, 0, 0, s3);

	ferret_create(40, 1, 0, FERRET_SCALAR, 0, 0, s4);

	s1->data=10;

	s2->data=20;

	s3->data=30;

	s4->data=40;

	printf("-= Done creating sensors. Starting to produce data.=-\n");

	while (1) {
		s1->data+=1;
		s2->data+=1;
		s3->data+=1;
		s4->data+=1;
		t.msleep(200);
	}

    return 0;
}
