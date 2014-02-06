#iSpeakThrift thrift

service iSpeakThrift
{
    string stat();
    string get_opt();
    bool set_opt(1:string options);
}
