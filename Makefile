all:github



GITHUB_COMMIT := $(COMMIT)


ifeq ($(COMMIT), )
	GITHUB_COMMIT="subsystem/cpuusageutils, 基本完成获取CPU使用率的接口..."
endif


.PHONY	:	github
github :
	git pull
	git add -A
	git commit -m $(GITHUB_COMMIT)
	git push origin master


