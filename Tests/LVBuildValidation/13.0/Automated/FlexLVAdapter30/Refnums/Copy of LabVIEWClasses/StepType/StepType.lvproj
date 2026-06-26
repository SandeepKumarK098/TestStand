<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="13008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="NI.SortType" Type="Int">3</Property>
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Edit.vi" Type="VI" URL="../Edit.vi"/>
		<Item Name="DoOperationPreview.vi" Type="VI" URL="../DoOperationPreview.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="SimpleArithmetic.lvclass" Type="LVClass" URL="../../ClassDefinitions/SimpleClassWithMethods/SimpleArithmetic.lvclass"/>
			<Item Name="Create Class Instance.vi" Type="VI" URL="../../ClassDefinitions/SimpleClassWithMethods/Create Class Instance.vi"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
