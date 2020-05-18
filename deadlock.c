// PPT 6 - DEADLOCK AVOIDANCE
//global data structure
struct state{
	int resource[m];
	int available[m];
	int claim[n][m];
	int alloc[n][m];
};

//resource alloc algorithm
if(alloc[i, *] + request[*] > claim[i,*])
	<error>;
else if(request[*] > available[*])
	<suspend process>;
else{
	<define newstate by:
	alloc[i,*] = alloc[i,*] + request[*];
	available[*] = available[*] - request[*]>;
}
if(safe(newstate))
	<carry out allocation>;
else{
	<restore original state>;
	<suspend process>;
}

//test for safety algorithm (banker algorithm)
boolean safe(state S){
	int currentavail[m];
	process rest[<number of processes>];
	currentavail = available;
	rest = {all processes};
	possible = true;
	while(possible){
		<find a process Pk in rest such that
		claim [k,*] - alloc[k,*] <= currentavail;>
		
		if (found){
			currentavail = currentavail + alloc[k,*];
			rest = rest - {Pk};
		}
		else possible = false;
	}
	return (rest == null);
}
