import angr
import claripy
import sys

SIZE = 20

project = angr.Project('./a.out')

argv = claripy.BVS('argv', 8 * SIZE)

initial_state = project.factory.entry_state(args=['./a.out', argv])

simulation = project.factory.simgr(initial_state)
simulation.explore(find=lambda s: b'Access Granted!\n' in s.posix.dumps(sys.stdout.fileno()))

for final in simulation.found:
    print(final.solver.eval(argv, cast_to=bytes))
