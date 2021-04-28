if [ ! -f grads ]; then
	ln -s /nfs/stak/faculty/p/parhammj/grads-2.0.1/bin/grads grads
fi

if [ ! -f ./heatdiff.ctl ]; then
	curl -S classes.engr.oregonstate.edu/eecs/fall2017/cs160h-001/assignments/heatdiff.ctl > heatdiff.ctl
fi
	
if [ ! -f ./1d_grads_script.gs ]; then
	curl -S classes.engr.oregonstate.edu/eecs/fall2017/cs160h-001/assignments/1d_grads_script.gs > 1d_grads_script.gs
fi

if [ ! -f ./2d_grads_script.gs ]; then
	curl -S classes.engr.oregonstate.edu/eecs/fall2017/cs160h-001/assignments/2d_grads_script.gs > 2d_grads_script.gs
fi

if [ ! -f ./heatdiff2.ctl ]; then
	curl -S classes.engr.oregonstate.edu/eecs/fall2017/cs160h-001/assignments/heatdiff2.ctl > heatdiff2.ctl
fi


if [ ! -f ./helper.hpp ]; then
	curl -S classes.engr.oregonstate.edu/eecs/winter2019/cs161-001/heat_diffusion/helper.hpp > helper.hpp
fi

echo "run the command \"export GADDIR=/nfs/stak/faculty/p/parhammj/grads-2.0.1/lib\""
