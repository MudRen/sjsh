
#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
        object obj;
        string err, msg;

        seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("ʲô��\n");

        file = resolve_path(me->query("cwd"), file);
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        me->set("cwf", file);

        if( file_size(file) < 0 )
                return notify_fail("ʲô��\n");

        if( !find_object(file) ) {
                err = catch(call_other(file, "???"));
                if (err) {
                        write("ʲô��\n");
                        return 1;
                }
        }

        err = catch(obj = new(file));
        if (err) {
                write("ʲô��\n");
                return 1;
        }

        if( !stringp(msg = me->query("env/msg_clone")) )
                msg = "\n";

        if( !obj->is_character() && obj->move(me) ) {
                write(obj->query("name") + "");
        message_vision(msg + "\n", me, obj);
                return 1;
        }
        if( obj->move(environment(me)) ) {
                write(obj->query("name") + "ʲô��\n");
        message_vision(msg + "\n", me, obj);
                return 1;
        }

        destruct(obj);
        return notify_fail("ʲô��\n");
}


