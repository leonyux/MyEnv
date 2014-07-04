#!/usr/bin/env python

import threading
import logging
import xml.etree.ElementTree

class A(object):
    def run(self):
        self.thread = threading.Thread(target=self.daemon, args=())
        self.thread.start()

    def daemon(self):
        try:
            print str(self) + 'haha'
            raise Exception('a')
        except Exception, e:
            #logging.error(e)
            #logging.error('b')
            #logging.exception(e)
            logging.exception('b')

    def returnT(self):
        return ()

if __name__ == '__main__':
    a = A()
    a.run()
    b = ''
    try:
        b = xml.etree.ElementTree.fromstring('<a>')
    except Exception, e:
        logging.exception('c')
        pass
    print b
    print 'haha'
    if a.returnT():
        print '1'
    if a.returnT() != None:
        print '2'
