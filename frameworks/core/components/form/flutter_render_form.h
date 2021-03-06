/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FOUNDATION_ACE_FRAMEWORKS_CORE_COMPONENTS_FORM_FLUTTER_RENDER_FORM_H
#define FOUNDATION_ACE_FRAMEWORKS_CORE_COMPONENTS_FORM_FLUTTER_RENDER_FORM_H

#include "core/components/form/render_form.h"
#include "core/pipeline/layers/offset_layer.h"

namespace OHOS::Ace {

class FlutterRenderForm : public RenderForm {
DECLARE_ACE_TYPE(FlutterRenderForm, RenderForm);

public:
    FlutterRenderForm() = default;
    ~FlutterRenderForm() override = default;

    RenderLayer GetRenderLayer() override;

    std::unique_ptr<DrawDelegate> GetDrawDelegate() override;

    void RemoveChildren() override;

    void NotifyPaintFinish() override;
private:
    RefPtr<Flutter::OffsetLayer> layer_;
};

} // namespace OHOS::Ace

#endif // FOUNDATION_ACE_FRAMEWORKS_CORE_COMPONENTS_FORM_FLUTTER_RENDER_FORM_H
