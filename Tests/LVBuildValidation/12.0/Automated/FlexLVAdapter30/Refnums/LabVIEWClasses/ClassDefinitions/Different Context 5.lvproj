<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="12002189">
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
		<Item Name="SimpleClassWithMethods" Type="Folder">
			<Item Name="Create Class Instance.vi" Type="VI" URL="../SimpleClassWithMethods/Create Class Instance.vi"/>
			<Item Name="DoOperationDynamicDispatchMethod Wrapper.vi" Type="VI" URL="../SimpleClassWithMethods/DoOperationDynamicDispatchMethod Wrapper.vi"/>
			<Item Name="DoOperationStaticDispatchMethod Wrapper.vi" Type="VI" URL="../SimpleClassWithMethods/DoOperationStaticDispatchMethod Wrapper.vi"/>
			<Item Name="Read Result Wrapper.vi" Type="VI" URL="../SimpleClassWithMethods/Read Result Wrapper.vi"/>
			<Item Name="SetNumbersAndOperationMethod Wrapper.vi" Type="VI" URL="../SimpleClassWithMethods/SetNumbersAndOperationMethod Wrapper.vi"/>
		</Item>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="SimpleArithmetic.lvclass" Type="LVClass" URL="../SimpleClassWithMethods/SimpleArithmetic.lvclass"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
