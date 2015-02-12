window_width = 800
window_height = 600
--------------------
BTN_ID_DOC_NEW = {
   pos = {x="window_width - BTN_ID_DOC_NEW.size.width", y="BTN_ID_DOC_NEW.size.height*2 - BTN_ID_DOC_NEW.size.height*1"},
   textures = {idle = "media/textures/button_document_new.png", hover = "media/textures/button_document_new.png", press = "media/textures/button_document_new.png"},
   size = {width="40", height="40"},
   text = "New Sketch"
}

BTN_ID_DOC_OPEN = {
    pos = {x="window_width - BTN_ID_DOC_OPEN.size.width", y="BTN_ID_DOC_OPEN.size.height*2"},
    textures = {idle = "media/textures/button_document_open.png", hover = "media/textures/button_document_open.png", press = "media/textures/button_document_open.png"},
    size = {width="40", height="40"},
    text = "Open Sketch"
}

BTN_ID_DOC_SAVE = {
    pos = {x="window_width - BTN_ID_DOC_SAVE.size.width", y="BTN_ID_DOC_SAVE.size.height*2 + BTN_ID_DOC_SAVE.size.height*1"},
    textures = {idle = "media/textures/button_document_save.png", hover = "media/textures/button_document_save.png", press = "media/textures/button_document_save.png"},
    size = {width="40", height="40"},
    text = "Save Sketch"
}
--------------------
BTN_ID_SELECT_VERTICAL = {
    pos = {x="window_width / 2 - BTN_ID_SELECT_VERTICAL.size.width / 2 - BTN_ID_SELECT_VERTICAL.size.width", y="window_height - 2 * BTN_ID_SELECT_VERTICAL.size.height"},
    size = {width="60", height="60"}
}

BTN_ID_SELECT_HORIZONTAL = {
    pos = {x="window_width / 2 - BTN_ID_SELECT_HORIZONTAL.size.width / 2 + BTN_ID_SELECT_HORIZONTAL.size.width", y="window_height - 2 * BTN_ID_SELECT_HORIZONTAL.size.height"},
    size = {width="60", height="60"}
}
--------------------
BTN_ID_CONFIRM_PLANE = {
    pos = {x="BTN_ID_CONFIRM_PLANE.size.width / 2", y="window_height - 2 * BTN_ID_CONFIRM_PLANE.size.height"},
    size = {width="60", height="60"}
}

BTN_ID_CANCEL_PLANE = {
    pos = {x="BTN_ID_CANCEL_PLANE.size.width / 2 + BTN_ID_CANCEL_PLANE.size.width * 1.2", y="window_height - 2 * BTN_ID_CANCEL_PLANE.size.height"},
    size = {width="60", height="60"}
}
--------------------
BTN_ID_DRAW_PLANE_DONE = {
    pos = {x="window_width - BTN_ID_DRAW_PLANE_DONE.size.width", y="window_height - 2 * BTN_ID_DRAW_PLANE_DONE.size.height"},
    size = {width="60", height="60"}
}

BTN_ID_DELETE_LINE_DONE = {
    pos = {x="window_width - BTN_ID_DELETE_LINE_DONE.size.width", y="window_height - 2 * BTN_ID_DELETE_LINE_DONE.size.height"},
    size = {width="60", height="60"}
}
--------------------
BTN_ID_STANDARD_VIEW = {
    pos = {x="window_width / 2 - BTN_ID_STANDARD_VIEW.size.width * 2 * 1.2", y="BTN_ID_STANDARD_VIEW.size.height / 2"},
    size = {width="60", height="60"}
}

BTN_ID_UNDO = {
    pos = {x="window_width / 2 - BTN_ID_UNDO.size.width * 1.2", y="BTN_ID_UNDO.size.height / 2"},
    size = {width="60", height="60"}
}

BTN_ID_DELETE_LINE = {
    pos = {x="window_width / 2", y="BTN_ID_DELETE_LINE.size.height / 2"},
    size = {width="60", height="60"}
}

BTN_ID_MIRROR = {
    pos = {x="window_width / 2 + BTN_ID_STANDARD_VIEW.size.width * 1.2", y="BTN_ID_MIRROR.size.height / 2"},
    size = {width="60", height="60"}
}