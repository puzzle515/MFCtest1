
void SHOW_VTK()
{
	CString address, pInfoC, pInfoS, pInfoL, pInfoO;
	SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(old_p);
	CString itype, isheet, isx, isy;
	itype.Format(_T("%d"), pSCharInfo->m_type);
	isheet.Format(_T("%d"), pSCharInfo->m_sheet);
	isx.Format(_T("%d"), pSCharInfo->m_sx);
	isy.Format(_T("%d"), pSCharInfo->m_sy);

	address = _T("C:\\Users\\qmqal\\Desktop\\04_3d\\");

	address += pSCharInfo->m_char + "_" + itype + ".stl";
	//주소합성

	vtkSmartPointer<vtkSTLReader> pSTLReader =
		vtkSmartPointer<vtkSTLReader>::New();




	pSTLReader->SetFileName(address);
	pSTLReader->Update();

	vtkSmartPointer<vtkPolyData> pPolyData =
		pSTLReader->GetOutput();

	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(pPolyData);
	vtkSmartPointer<vtkActor> actor =
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();
	renderer->AddActor(actor);
	renderer->SetBackground(.1, .2, .3);
	renderer->ResetCamera();


	vtkSmartPointer<vtkLight> newLight = vtkSmartPointer<vtkLight>::New();
	newLight->SetColor(0.7529, 0.7529, 0.7529);
	newLight->SetFocalPoint(0, 0, 0);
	newLight->SetPosition(-1, -0.5, 2);

	vtkSmartPointer<vtkLight> newLight2 = vtkSmartPointer<vtkLight>::New();
	newLight2->SetColor(0.7529, 0.7529, 0.7529);
	newLight2->SetFocalPoint(0, 0, 0);
	newLight2->SetPosition(1, 0.5, -2);

	renderer->AddLight(newLight);
	renderer->AddLight(newLight2);

	m_vtkWindow->AddRenderer(renderer);
	m_vtkWindow->Render();
}