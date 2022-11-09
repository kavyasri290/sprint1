SRCDIR = src
INCLUDEDIR = include
OBJDIR = obj
BINDIR = bin
VALGRIND = tools/valgrind.txt

INCLUDEFLAGS = -I${INCLUDEDIR}
CPPFLAGS = -ansi -c -g -Wall -DDEBUG ${INCLUDEFLAGS}

final: job.o cut.o bend.o polish.o pattern.o MachineScheduler.o main.o
	g++ -o ${BINDIR}/final ${OBJDIR}/job.o ${OBJDIR}/cut.o ${OBJDIR}/bend.o ${OBJDIR}/polish.o ${OBJDIR}/pattern.o ${OBJDIR}/MachineScheduler.o ${OBJDIR}/main.o
main.o : ${SRCDIR}/main.cpp
	g++ -o ${OBJDIR}/main.o ${CPPFLAGS} ${SRCDIR}/main.cpp

MachineScheduler.o : ${SRCDIR}/machinescheduler.cpp
	g++ -o ${OBJDIR}/MachineScheduler.o ${CPPFLAGS} ${SRCDIR}/machinescheduler.cpp

pattern.o : ${SRCDIR}/pattern.cpp

	g++ -o ${OBJDIR}/pattern.o ${CPPFLAGS} ${SRCDIR}/pattern.cpp
polish.o : ${SRCDIR}/polish.cpp
	g++ -o ${OBJDIR}/polish.o ${CPPFLAGS} ${SRCDIR}/polish.cpp

bend.o : ${SRCDIR}/bend.cpp
	g++ -o ${OBJDIR}/bend.o ${CPPFLAGS} ${SRCDIR}/bend.cpp

cut.o : ${SRCDIR}/cut.cpp
	g++ -o ${OBJDIR}/cut.o ${CPPFLAGS} ${SRCDIR}/cut.cpp

job.o : ${SRCDIR}/job.cpp
	g++ -o ${OBJDIR}/job.o ${CPPFLAGS} ${SRCDIR}/job.cpp

valgrind: $(BIN)/final
	valgrind --leak-check=full --show-reachable=yes $(BIN)/final 2>$(VALGRIND)/valgrind.txt
clean :
	echo "cleaning up .o and exes"
	rm ${BINDIR}/final ${OBJDIR}/main.o ${OBJDIR}/job.o

