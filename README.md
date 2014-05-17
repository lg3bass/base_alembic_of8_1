base_alembic_of8_1
==================
2014-05-17
Original project: https://github.com/lg3bass/base_alembic


Description
===========
Simple project illustrating ofxAlembic/Maya usage. 

Dependencies
============
- Uses is the latest version of ofxAlembic. https://github.com/perfume-dev/ofxAlembic
- Updated to use OF 8.1 (ofApp instead of testApp)
- ofxGui
- ofxXmlSettings

Goals
=====
- Figure out how to export geometry from Maya to be used in OF.
- Work out the scaling issue.  When I export using the default settings the models are huge in OF. (Maya models default export to CM not M)
- figure out how to export normals from Maya. HINT: Gotta set the normal angle (~ 20-25). Otherwise it doesn't show shading.

Maya
=======
vbo_5b.mb -- this file I exported from.  My sample content is series of animated lofts (e.g ribbons).