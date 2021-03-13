class CfgDisabledCommands
{
    class CREATEUNIT
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"STRING"},{"ARRAY"}};
        };

        class SYNTAX2
        {
            targets[] = {1,0,1};
            args[] = {{"GROUP"},{"ARRAY"}};
        };
    };

    class ALLVARIABLES
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{},{"CONTROL"}};
        };

        class SYNTAX2
        {
            targets[] = {1,0,1};
            args[] = {{},{"DISPLAY"}};
        };

        class SYNTAX3
        {
            targets[] = {1,0,1};
            args[] = {{},{"TEAM_MEMBER"}};
        };

        class SYNTAX4
        {
            targets[] = {1,0,1};
            args[] = {{},{"NAMESPACE"}};
        };

        class SYNTAX5
        {
            targets[] = {1,0,1};
            args[] = {{},{"OBJECT"}};
        };

        class SYNTAX6
        {
            targets[] = {1,0,1};
            args[] = {{},{"GROUP"}};
        };

        class SYNTAX7
        {
            targets[] = {1,0,1};
            args[] = {{},{"TASK"}};
        };

        class SYNTAX8
        {
            targets[] = {1,0,1};
            args[] = {{},{"LOCATION"}};
        };
    };

	class CREATEMINE
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{},{"ARRAY"}};
        };
    };

	class ADDMPEVENTHANDLER
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"OBJECT"},{"ARRAY"}};
        };
    };

    class REMOVEMPEVENTHANDLER
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"OBJECT"},{"ARRAY"}};
        };
    };

	class CREATEVEHICLE
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"STRING"},{"ARRAY"}};
        };

        class SYNTAX2
        {
            targets[] = {1,1,1};
            args[] = {{},{"ARRAY"}};
        };
    };
};