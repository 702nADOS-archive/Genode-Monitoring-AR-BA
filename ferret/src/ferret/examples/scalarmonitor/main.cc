#include <base/env.h>
#include <base/printf.h>
#include <sensordir_session/client.h>
#include <sensordir_session/connection.h>
#include <dataspace/client.h>
#include <sensors/scalar.h>
#include <timer_session/connection.h>
#include <monitor.h>

using namespace Genode;

int main(void)
{
	uint32_t start_time = 0;

	uint32_t end_time = 0;
	
	Timer::Connection t;

	t.msleep(100);

	printf("Hello from the scalar monitor.\n");

	ferret_scalar_t * s1 = NULL, * s2 = NULL, * s3 = NULL, * s4 = NULL;

	ferret_att(10, 1, 0, s1);

	ferret_att(20, 1, 0, s2);

	ferret_att(30, 1, 0, s3);

	ferret_att(40, 1, 0, s4);


	while (1) {		
		printf("***************************\n");
		printf("%d\n", s1->data);
		printf("%d\n", s2->data);
		printf("%d\n", s3->data);
		printf("%d\n", s4->data);
		t.msleep(0.5);
	}

    return 0;
}
