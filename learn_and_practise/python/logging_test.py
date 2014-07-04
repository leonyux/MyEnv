#!/usr/bin/env python

import logging
logging.basicConfig(filename='example.log', filemode='w',level=logging.DEBUG)
logger = logging.getLogger(__name__)
logger.debug('This message should go to the log file')
logger.info('So should this')
logger.warning('And this, too')
