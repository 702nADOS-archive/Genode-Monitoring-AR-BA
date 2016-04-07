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
	uint32_t start_time = 0;

	uint32_t end_time = 0;

	Timer::Connection t;

	t.msleep(50);

	printf("Hello from the scalar demo.\n");

	ferret_scalar_t * s1 = NULL, * s2 = NULL, * s3 = NULL, * s4 = NULL;

	ferret_create(10, 1, 0, FERRET_SCALAR, 0, 0, s1);

	ferret_create(20, 1, 0, FERRET_SCALAR, 0, 0, s2);

	ferret_create(30, 1, 0, FERRET_SCALAR, 0, 0, s3);

	ferret_create(40, 1, 0, FERRET_SCALAR, 0, 0, s4);

	s1->data=10;

	s2->data=10;

	s3->data=-10;

	s4->data=-10;

	printf("-= Done creating sensors. Starting to produce data.=-\n");

	while (1) {
		s1->data+=1;
		s2->data+=10;
		s3->data-=1;
		s4->data-=10;		
		t.msleep(0.5);
	}

    return 0;
}
