LIBRARIES_DIR=libraries
TEST_DIR=test

PHONY=

PHONY+=configure-libraries
configure-libraries:
	cd ${LIBRARIES_DIR} \
	&& cmake -B build

PHONY+=build-libraries
build-libraries: configure-libraries
	cd $(LIBRARIES_DIR) \
	&& cmake --build build

PHONY+=configure-test
configure-test:
	cd $(TEST_DIR) \
	&& cmake -B build

PHONY+=build-test
build-test: configure-test
	cd $(TEST_DIR) \
	&& cmake --build build

PHONY+=clean
clean:
	cd $(LIBRARIES_DIR) && rm -rf build
	cd $(TEST_DIR) && rm -rf build

PHONY+=clean-build-all
clean-build-all: clean configure-libraries configure-test build-libraries build-test


# PHONY+=clean-multi
# clean-multi:configure-multi
# 	cmake -- build \
# 			--preset multi \
# 			--clean-first

.phony: ${PHONY}